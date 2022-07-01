#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

struct Color
{
    int r = 234, g = 221, b = 202; /*Almond Yellow as default color*/
};

struct Point3 /*3d unit*/
{
    float x, y, z = 0; 
};

struct Vertex : Point3  /*Vertex is a point that communcate points and have color variable besides position*/
{
    Color c; 
};

struct Triangle
{
    Vertex a,b,c;/*                              ..a   <--- First vertex
                                                 // |  
                                                //  |                    
                My tryangle name system.       //   |
                                              //    |
                                             //_____|    
                       Second Vertex   --->  c       b   <--- Base Vertex
    */
};


int main()
{
    /*Pointer to program window*/
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    /*Generate random Y-coordinate matrix*/
    const int n = 8;
    Vertex a[n][n]; /*Matrix of vertexes*/

    for (int i = 0; i < n; i++) //filling matrix 8*8 size (n*n) 
    {
        for (int j = 0; j < n; j++)
        {
            //landscape exist in range [-1;1] in each coordinate system
            a[i][j].x = -1 + ((2 / n) * j); //creating equal distance points for landscape by X coordinate 
            a[i][j].z = -1 + ((2 / n) * i); //creating equal distance points for landscape by Z coordinate 
            a[i][j].y = ((rand() % 200) - 100) / 100.f; //generate random Y height with 2 decimals
        }
    }

    /*Triangulazing landscape*/
    const int s = 128; 
    //Count of triangles are defining by formula 
    //-> (n^2)*2 because n^2 is count of squares in place 
    //-> triangles is x2. So we can compact it in to 2^n-1 
    Triangle v[s];

    int t = 0;  //in iteration we blending square in 2 triangles. So the step will be 2.
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 1; j++)
        {
            /*Point by point. Blending land*/
            v[t].a = a[j][i];
            v[t].b = a[j][i + 1];
            v[t].c = a[j + 1][i + 1];

            v[t + 1].a = v[t].a;
            v[t + 1].b = a[j + i][i];
            v[t + 1].c = v[t].c;
            t += 2;
        }
    }
    /*Matrix filled and blended by triangles*/

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "Dod2007", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}