//
// Created by wlanjie on 2019/4/13.
//

#ifndef TRINITY_FRAME_BUFFER_H
#define TRINITY_FRAME_BUFFER_H

#include "opengl.h"

#define FIX_XY 0
#define CROP   1

#define FRAME_VERTICAL                                            0
#define FRAME_HORIZONTAL                                          1
#define FRAME_SQUARE                                              2

namespace trinity {

class FrameBuffer : public OpenGL {
public:
    FrameBuffer(int width, int height, const char* vertex, const char* fragment);
    FrameBuffer(int width, int height, int view_width, int view_height, const char* vertex, const char* fragment);
    FrameBuffer(int render_type, int width, int height, int view_width, int view_height, const char* vertex, const char* fragment);
    void CompileFrameBuffer(int view_width, int view_height, int camera_width, int camera_height);
    ~FrameBuffer();

    void SetStartTime(uint64_t time);
    void SetEndTime(uint64_t time);
    void SetRenderType(int type);
//    void Init(const char* vertex, const char* fragment);
    GLuint OnDrawFrame(GLuint texture_id, uint64_t current_time = 0);
    GLuint OnDrawFrame(GLuint texture_id, GLfloat* matrix, uint64_t current_time = 0);
    GLuint OnDrawFrame(GLuint texture_id, const GLfloat* vertex_coordinate, const GLfloat* texture_coordinate, uint64_t current_time = 0);

    GLuint GetTextureId() {
        return texture_id_;
    }

    void SetFrame(int frame, int screen_width, int screen_height);

private:
    void ResetVertexCoordinate();
private:
    GLuint texture_id_;
    GLuint frameBuffer_id_;
    GLfloat* vertex_coordinate_;
    GLfloat* texture_coordinate_;
    int view_width_;
    int view_height_;
    int camera_width_;
    int camera_height_;
    uint64_t start_time_;
    uint64_t end_time_;
};

}

#endif //TRINITY_FRAME_BUFFER_H
