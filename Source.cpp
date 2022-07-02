#include <iostream>
#include <GLFW/glfw3.h>

using namespace std;

struct Color
{
    int r = 255, g = 255, b = 255; /*White as default color*/
};

struct Point3 /*3d unit*/
{
    float x=0, y=0, z = 0; 
};

struct Vertex : Point3  /*Vertex is a point that communcate points and have color variable besides position*/
{
    Color c; 
};

struct Triangle
{
    Vertex a,b,c;/*                                 .a   <--- First vertex
                                                   /|
                                                  / |  
                                                 /  |                    
                My tryangle name system.        /   |
                                               /    |
                                              /_____|    
                       Second Vertex   ---> c        b   <--- Base Vertex
    */
};


int main()
{
    /*Pointer to program window*/
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;


    /*Generate random Y-coordinate Grid*/
    const int n = 8; /*Matrix size*/
    const int g =  n+1; /*Count of grids in line*/
    Vertex a[g][g]; /*Grid of vertexes*/

    for (int i = 0; i < g; i++) //filling vertexes grid 
    {
        for (int j = 0; j < g; j++)
        {
            //landscape exist in range [-1;1] in each coordinate system
            a[i][j].x = -1 +((2.f / (n)) * (j)); //creating equal distance points for landscape by X coordinate 
            a[i][j].y = -1 +((2.f / (n)) * (i)); //creating equal distance points for landscape by y coordinate 
            a[i][j].z = (rand() % 100) / 100.f; //generate random z height with 2 decimals
            cout << "(" << a[i][j].x<<','<< a[i][j].z<<','<< a[i][j].y<<"),";
        }
        cout << endl;
    }

    /*Triangulazing landscape*/
    const int s = (n*n)*2;
    //Count of triangles are defining by formula 
    //-> (n^2)*2 because n^2 is count of squares in place 
    Triangle v[s];

    int t = 0;  //in iteration we blending square in 2 triangles. So the step will be 2.
    for (int y = 0; y < n; y++)
    {
        for (int x = 0; x < n; x++)
        {
            v[t].a = a[y + 1][x + 1];
            v[t].b = a[y][x + 1];
            v[t].c = a[y][x];

            v[t + 1].a = v[t].c;
            v[t + 1].c = a[y + 1][x];
            v[t + 1].b = v[t].a;
            t+=2;
        }
    }
    cout << t << endl;

    /*Grid filled and blended by triangles*/

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 640, "Dod2007", NULL, NULL);
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

        
        glBegin(GL_TRIANGLES);
            for (int i = 0; i < s; i++)
            {   
                glVertex3f(v[i].a.x, v[i].a.y, v[i].a.z);
                glColor3f(255, 0, 0);
                glVertex3f(v[i].b.x, v[i].b.y, v[i].b.z);
                glColor3f(0, 0, 255);
                glVertex3f(v[i].c.x, v[i].c.y, v[i].c.z);
                glColor3f(0, 255, 0);
            }
        glEnd();

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}