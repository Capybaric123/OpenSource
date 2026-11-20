#ifndef VAO_H
#define VAO_H

#include <glad/gl.h>
#include "vbo.h"

struct CVao {
	GLuint m_uHandle;
};

struct CVao m_VaoCreate();
void m_VaoDestroy(struct CVao m_Self);
void m_VaoBind(struct CVao m_Self);
void m_VaoUnbind();
void m_VaoAttr(struct CVao m_Self, struct CVbo m_Vbo, GLuint m_uIndex, GLint m_iSize, GLenum m_eType, GLsizei m_Stride, size_t m_Offset);

#endif