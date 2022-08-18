#include "Buffer.h"

Buffer::~Buffer()
{
	glDeleteBuffers(1, &buffer);
}