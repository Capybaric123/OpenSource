#ifndef R_VBO_H
#define R_VBO_H

#include <glad/gl.h>
#include <cglm/struct.h>

struct CVbo {
	GLuint m_uHandle;
	GLint m_iType;
	bool m_bDynamic;
};

struct CVbo m_VboCreate(GLint iType, bool bDynamic);

void m_VboDestroy(struct CVbo m_Self);
void m_VboBind(struct CVbo m_Self);
void m_VboUnbind(struct CVbo m_Self);
void m_VboData(struct CVbo m_Self, void *m_pData, GLsizeiptr m_pSize);

#endif