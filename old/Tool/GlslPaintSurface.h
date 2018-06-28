#ifndef EXAMPLEPAINTSURFACE_H
#define EXAMPLEPAINTSURFACE_H

#include "OpenGlOffscreenSurface.h"
#include <QOpenGLShaderProgram>
#include <QSize>
class GlslPaintSurface
    : public OpenGlOffscreenSurface
{
public:
    explicit GlslPaintSurface(
            QScreen* targetScreen = nullptr,
            const QSize& size = QSize (300, 200));

    virtual ~GlslPaintSurface() override;


    //ͨ���ļ���   �����µ� Fragment ����
    void setFragmentByFile(const QString& filename);

    //ͨ��QString �����µ� Fragment ����
    void setFragmentByCode(const QString& code);
protected:
    virtual void initializeGL() override;

    virtual void resizeGL(int width,int height) override;

    virtual void paintGL() override;
private:
    QOpenGLShaderProgram    *m_program;
    QSize   m_size;
};


#endif  // EXAMPLEPAINTSURFACE_H

