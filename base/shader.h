#ifndef SHADER_H
#define SHADER_H

#define GLM_FORCE_RADIANS

#include <string>
#include <GL/glew.h>
#include "transform.h"
#include "camera.h"

class Shader
{
    public:
        Shader( const std::string& filename);

        void Bind();

        void Update(const Transform& transofrm, const Camera& camera);

        virtual ~Shader();
    protected:
    private:
        static const unsigned int NUM_SHADERS = 2;
        Shader(const Shader& other);
        void operator=(const Shader& other);

        enum {
            TRANSFORM_U,

            NUM_UNIFORMS
        };

        GLuint m_program;
        GLuint m_shaders[NUM_SHADERS];
        GLuint m_uniforms[NUM_UNIFORMS];
};

#endif // SHADER_H
