// Shipeng Xu
// billhsu.x@gmail.com

#include "IMGUIImpl.h"
#include <queue>
#include "OpenGL/HardwareBuffer/HardwareBuffer.h"

namespace IMGUIImpl {
    HardwareBuffer buffer;
    HardwareBuffer::VBOStruct VBOInfo;
    float verticesArray[8];
    float uvArray[8];
    float colorArray[16];
    int indices[6];
    float mR = 1, mG = 1, mB = 1, mAlpha = 1;
    void prepareRenderData() {
        init();
        uvArray[0] = 0.0f;
        uvArray[1] = 0.0f;
        uvArray[2] = 1.0f;
        uvArray[3] = 0.0f;
        uvArray[4] = 1.0f;
        uvArray[5] = 1.0f;
        uvArray[6] = 0.0f;
        uvArray[7] = 1.0f;

        indices[0] = 0;
        indices[1] = 1;
        indices[2] = 2;
        indices[3] = 0;
        indices[4] = 2;
        indices[5] = 3;

        colorArray[0] = mR;
        colorArray[1] = mG;
        colorArray[2] = mB;
        colorArray[3] = mAlpha;
        colorArray[4] = mR;
        colorArray[5] = mG;
        colorArray[6] = mB;
        colorArray[7] = mAlpha;
        colorArray[8] = mR;
        colorArray[9] = mG;
        colorArray[10] = mB;
        colorArray[11] = mAlpha;
        colorArray[12] = mR;
        colorArray[13] = mG;
        colorArray[14] = mB;
        colorArray[15] = mAlpha;
        VBOInfo.vertexBufferSize = sizeof(verticesArray) / sizeof(float);
        VBOInfo.vertexBufferData = verticesArray;
        VBOInfo.uvBufferSize = sizeof(uvArray) / sizeof(float);
        VBOInfo.uvBufferData = uvArray;
        VBOInfo.colorBufferSize = sizeof(colorArray) / sizeof(float);
        VBOInfo.colorBufferData = colorArray;
        VBOInfo.indexBufferSize = sizeof(indices) / sizeof(int);
        VBOInfo.indexBufferData = indices;
        unsigned int flags = HardwareBuffer::FLAG_VERTEX_BUFFER |
                             HardwareBuffer::FLAG_UV_BUFFER |
                             HardwareBuffer::FLAG_COLOR_BUFFER |
                             HardwareBuffer::FLAG_INDEX_BUFFER;

        buffer.initVBO(VBOInfo, flags);
        buffer.setVBOLocation(HardwareBuffer::FLAG_VERTEX_BUFFER, 0);
        buffer.setVBOLocation(HardwareBuffer::FLAG_UV_BUFFER, 1);
        buffer.setVBOLocation(HardwareBuffer::FLAG_COLOR_BUFFER, 2);

        buffer.setVBOUnitSize(HardwareBuffer::FLAG_VERTEX_BUFFER, 2);
        buffer.setVBOUnitSize(HardwareBuffer::FLAG_UV_BUFFER, 2);
        buffer.setVBOUnitSize(HardwareBuffer::FLAG_COLOR_BUFFER, 4);
    }
    void renderButton(RenderItem renderItem) {
        verticesArray[0] = renderItem.vertices[0].x;
        verticesArray[1] = renderItem.vertices[0].y;
        verticesArray[2] = renderItem.vertices[1].x;
        verticesArray[3] = renderItem.vertices[1].y;
        verticesArray[4] = renderItem.vertices[2].x;
        verticesArray[5] = renderItem.vertices[2].y;
        verticesArray[6] = renderItem.vertices[3].x;
        verticesArray[7] = renderItem.vertices[3].y;

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, renderItem.texID);
        HardwareBuffer::VBOStruct _VBO;
        _VBO.vertexBufferData = verticesArray;
        _VBO.vertexBufferSize = sizeof(verticesArray) / sizeof(float);
        buffer.updateVBO(_VBO, HardwareBuffer::FLAG_VERTEX_BUFFER);
        buffer.render();
        glBindTexture(GL_TEXTURE_2D, 0);
    }
    void render() {
        glDisable(GL_DEPTH_TEST);
        glDepthMask(GL_FALSE);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glEnable(GL_BLEND);

        std::queue<RenderItem> renderQueue = getRenderQueue();
        while (renderQueue.size() > 0) {
            RenderItem renderItem = renderQueue.front();
            renderQueue.pop();
            switch (renderItem.type) {
                case RENDER_ITEM_BUTTON:
                    renderButton(renderItem);
                    break;
                case RENDER_ITEM_LABEL:
                    break;
                default:
                    break;
            }
        }

        glDepthMask(GL_TRUE);
        glDisable(GL_BLEND);
        glEnable(GL_DEPTH_TEST);
    }
};