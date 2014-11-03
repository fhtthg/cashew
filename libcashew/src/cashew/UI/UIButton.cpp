/* 
Shipeng Xu
billhsu.x@gmail.com
*/
#include "core/UI/UI.h"
#include "UIButton.h"
#include <iostream>
#include "impl/glut.h"
#include <math.h>
#include "core/math/Vectors.h"
#include "impl/Utility.h"
#include "core/scene/Controller.h"

UIButton::UIButton(UINode* parent) : UINode(parent)
{
    textureID_idle = textureID_hover = textureID_press = -1;
    std::cout<<"UIButton("<<parent<<")"<<std::endl;
}
UIButton::~UIButton()
{
    std::cout<<"~UIButton()"<<std::endl;
}
void UIButton::setText(const char* text)
{
    strcpy(mText, text);
}

void UIButton::MouseButton(int button, int state, int x, int y)
{
    if(state == 0)
    {
        nodeStatus = UINode::NODE_PRESS;
        mTimeAccu = 0.0f;
    }
    else if(state == 1)
    {
        if(mCallBackFunc!=NULL) mCallBackFunc(this);
        nodeStatus = UINode::NODE_IDLE;
        mTimeAccu = 0.0f;
        if(insideNode(x, y))
        {
            nodeStatus = UINode::NODE_HOVER;
            mTimeAccu = 0.0f;
        }
    }
}

void UIButton::PassiveMotion(int x, int y)
{
    if(insideNode(x, y))
    {
        if(UINode::NODE_HOVER != nodeStatus)
        {
            nodeStatus = UINode::NODE_HOVER;
            mTimeAccu = 0.0f;
        }
    }
    else
    {
        nodeStatus=UINode::NODE_IDLE;
        mTimeAccu = 0.0f;
    }
}

void UIButton::render(float timeDelta)
{
    float _alpha = mAlpha;
    float _height = mHeight;
    float _width = mWidth;

    mTimeAccu += timeDelta;

    if(isAnimation)
    {
        long curTimeMs = getMilliSec();
        float factor = (float)(curTimeMs - timeMsAniStart) / timeMsTotalForAni;
        if(aniStatus == UI_ANIM_IN)
        {
            _alpha  = mAlpha  * factor;
            _height = mHeight * sin(factor * 90 * PI / 180);
            _width  = mWidth  * sin(factor * 90 * PI / 180);
            if(curTimeMs - timeMsAniStart >= timeMsTotalForAni)
            {
                isAnimation = false;
            }
        }
        if(aniStatus == UI_ANIM_OUT)
        {
            factor  = 1.0f    - factor;
            _alpha  = mAlpha  * factor;
            _height = mHeight * sin(factor*90*PI/180);
            _width  = mWidth  * sin(factor*90*PI/180);
            if(curTimeMs - timeMsAniStart >= timeMsTotalForAni)
            {
                isAnimation = false;
                mIsVisible = false;
            }
        }
    }
    else if(nodeStatus == NODE_HOVER)
    {
        _height = mHeight * (0.96f + 0.04f * cos(mTimeAccu/90.0f));
        _width  = mWidth  * (0.96f + 0.04f * cos(mTimeAccu/90.0f));
    }

    glColor4f(mR, mG, mB, _alpha);

    GLuint textureID = -1;
    if(nodeStatus == UINode::NODE_IDLE) textureID = textureID_idle;
    else if(nodeStatus == UINode::NODE_HOVER) textureID = textureID_hover;
    else if(nodeStatus == UINode::NODE_PRESS) textureID = textureID_press;
    
    if(textureID!=-1)
    {
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, textureID);
    }
    float offset_x = (mWidth  - _width ) / 2.0f;
    float offset_y = (mHeight - _height) / 2.0f;
    glBegin(GL_QUADS);
        glTexCoord2f(0.0f,0.0f); glVertex2f(mPosX + offset_x, mPosY + offset_y);
        glTexCoord2f(1.0f,0.0f); glVertex2f(mPosX + offset_x +_width, mPosY + offset_y);
        glTexCoord2f(1.0f,1.0f); glVertex2f(mPosX + offset_x +_width, mPosY + offset_y +_height);
        glTexCoord2f(0.0f,1.0f); glVertex2f(mPosX + offset_x, mPosY + offset_y +_height);
    glEnd();
    if(textureID!=-1) glDisable(GL_TEXTURE_2D);

    if(nodeStatus == NODE_HOVER && mTimeAccu >= 600)
    {
        offset_x = 0.0f;
        offset_y = 0.0f;
        if(Controller::mouseX>=Controller::width - mWidth - 100) offset_x = - (strlen(mText) * 9);
        if(Controller::mouseY>=Controller::height - mHeight - 100) offset_y = - 15;
        strcpy(UI::uiHintText, mText);
        UI::hintTextPosX = Controller::mouseX + offset_x;
        UI::hintTextPosY = Controller::mouseY + offset_y;
    }
}