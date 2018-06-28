#ifndef GLVIEWWIDGET_H
#define GLVIEWWIDGET_H

#include <QGLWidget>
#include <QGLShaderProgram>
#include <QGLShader>
#include <QString>
#include <QDebug>
#include <opengl/freeglut.h>

class QTimer;
class GLViewWidget : public QGLWidget
{
    Q_OBJECT

public:
    explicit GLViewWidget(QWidget *parent = 0);
    ~GLViewWidget();

    //ͨ���ļ���   �����µ� Fragment ����
    void setFragmentByFile(const QString& filename);

    //ͨ��QString �����µ� Fragment ����
    void setFragmentByCode(const QString& code);

    void start();
    void stop();
protected:

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

protected:
    // ��ɫ������ shader program;
    QGLShaderProgram *m_program;

private slots:
    void slots_update();
private:
    GLfloat m_time;
    QTimer  *m_timer;
};

#endif // GLVIEWWIDGET_H
