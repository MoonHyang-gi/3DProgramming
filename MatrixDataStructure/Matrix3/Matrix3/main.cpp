#include <chrono>
#include <thread>
#include <string>
#include <iostream>
#include <GLFW/glfw3.h>
#include "MusoenMath.h"
#include <math.h>

#pragma comment(lib, "OpenGL32")

using namespace std;

chrono::system_clock::time_point startRenderTimePoint;
chrono::duration<double> renderDuration;

GLFWwindow* window;
bool isFirstFrame = true;


struct Vertex
{
    vec3 pos; //위치 설정을 위한 vec3
    float r, g, b, a;
};

struct Transform
{
    mat3 translate; //이동을 위한 mat3
    mat3 scale; //크기변환을 위한 mat3
    mat3 rotation; //회전을 위한 mat3
};


Vertex star[5];             // static mesh
Vertex transformedStar[5];  //화면에 그릴 오망성
Vertex circle[360];             // static mesh 
Vertex transformedCircle[360];  // 화면에 그려질 원

Transform transform;  //world 행렬이 될 transform

//<문제>////////전역변수 쓰는곳////////////////////////////////////////////////////////////

float rotation = 0;  //회전할 때 사용 될 float값 rotation 0으로 초기화
float scaling = 1.0f; //크기가 변할 때 사용 될 float값 scaling 1로 초기화
float moving = 0; //이동할 때 사용 될 flaot값 moving 0으로 초기화

bool isScaleMax; //bool 값으로 크기가 최대로 커졌는지 아닌지 체크

//////////////////////////////////////////////////////////////////////////////////////////

void Init();
void Update();
void Release();

static void error_callback(int error, const char* description);
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void);


void Init()
{
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        exit(EXIT_FAILURE);
    window = glfwCreateWindow(720, 720, "Simple example", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);


    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glfwSwapInterval(1);

    startRenderTimePoint = chrono::system_clock::now();


    //object생성부
     /// Star(오망성) 생성
    int i = 0;
    for (float theta = 0; theta < 360; theta += 72)
    {

        star[i].pos.x = -sin(theta * PI / 180) * 0.5f;
        star[i].pos.y = cos(theta * PI / 180) * 0.5f;
        star[i].pos.z = 1.0f;

        star[i].r = 0.3f;
        star[i].g = 0.0f;
        star[i].b = theta / 360.0f;
        star[i].a = 0.7f;


        transformedStar[i] = star[i];

        i++;
    }

    // 원 생성
    for (int theta = 0; theta < 360; theta++)
    {
        circle[theta].pos.x = -sin((float)theta * PI / 180) * 0.5;
        circle[theta].pos.y = cos((float)theta * PI / 180) * 0.5;
        circle[theta].pos.z = 1.0f;

        circle[theta].r = 0.3f;
        circle[theta].g = 0.0f;
        circle[theta].b = (float)theta / 360.0f;
        circle[theta].a = 0.7f;

        transformedCircle[theta] = circle[theta];
    }


    //트랜스폼 초기화 (기본형 제공)
    transform.translate = mat3( //x, y, z의 값이 1인 행렬
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );
    transform.rotation = mat3( //x, y의 값을 cos와 sin을 이용해 설정하고 z 값을 1로 둔 행렬
        cos(rotation * PI / 180), -sin(rotation * PI / 180), 0,
        sin(rotation * PI / 180), cos(rotation * PI / 180), 0,
        0, 0, 1
    );
    transform.scale = mat3( //x, y, z의 크기가 1인 행렬
        1, 0, 0,
        0, 1, 0,
        0, 0, 1
    );

}

void Release()
{
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Update()
{
    while (!glfwWindowShouldClose(window))
    {
        //Update로직
        //<문제>//////////////////////////////////////////////////////////////////////////////////

        //1. translate 를 프레임당 오른쪽으로 0.001씩 누적시켜서 물체를 이동해보세요.
        moving += 0.001f; //moving에 0.001씩 누적
        
        transform.translate = mat3( //x축으로 0.001씩 이동
            1, 0, 0,
            0, 1, 0,
            moving, 0, 1
        );

        //2. Rotation 을 프레임당 1도씩 누적시켜서 물체를 회전시켜보세요.
        rotation += 1; //rotation에 1씩 누적
        transform.rotation = mat3( //오른쪽으로 1도씩 회전
            cos(rotation * PI / 180), -sin(rotation * PI / 180), 0,
            sin(rotation * PI / 180), cos(rotation * PI / 180), 0,
            0, 0, 1
        );

        //3. Scale은 초당 0.01씩 최대 1.3배까지 늘어났다가 0.7배까지 줄어들도록 만드시오 (반복)
        //   (1.3배 이상이 되면 줄어들고 0.7배 이하가 되면 다시 늘어나게 만드시오)
        if (scaling >= 1.3f)
        {
            isScaleMax = true;
        }
        if (scaling <= 0.7f)
        {
            isScaleMax = false;
        }
        //값이 1.3 이상이면 0.01씩 줄어들고 값이 0.7이면 0.01씩 늘어남
        if (isScaleMax) 
            scaling -= 0.01f;
        else scaling += 0.01f;

        transform.scale = mat3( //x, y축으로 0.01도씩 늘어나거나 줄어듦
            scaling, 0, 0,
            0, scaling, 0,
            0, 0, 1
        );


        //////////////////////////////////////////////////////////////////////////////////////////


        //vec3 X mat3(scale, rotation, translate순)
        for (int i = 0; i < 360; i++)
        {                                       
            transformedCircle[i].pos = circle[i].pos * transform.scale * transform.rotation * transform.translate;
        }

        for (int i = 0; i < 5; i++)
        {
            transformedStar[i].pos = star[i].pos * transform.scale * transform.rotation * transform.translate;
        }



        //색 초기화
        glClearColor(.0f, 0.0f, 0.0f, 0.1f);
        glClear(GL_COLOR_BUFFER_BIT);

        //선두께
        glLineWidth(7.0f);
        //오망성 그리기
        glBegin(GL_LINE_STRIP);

        int a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 3;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 1;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 4;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        a = 2;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);

        a = 0;
        glColor4f(transformedStar[a].r, transformedStar[a].g, transformedStar[a].b, transformedStar[a].a);
        glVertex3f(transformedStar[a].pos.x, transformedStar[a].pos.y, 0.0f);
        glEnd();

        //원그리기
        glBegin(GL_LINE_STRIP);
        for (int theta = 0; theta < 360; theta++)
        {
            glColor4f(transformedCircle[theta].r, transformedCircle[theta].g, transformedCircle[theta].b, transformedCircle[theta].a);
            glVertex3f(transformedCircle[theta].pos.x, transformedCircle[theta].pos.y, 0.0f);
        }
        glEnd();



        //화면 스왑
        glfwSwapBuffers(window);
        glfwPollEvents();

        //렌더시간 측정
        renderDuration = chrono::system_clock::now() - startRenderTimePoint;
        startRenderTimePoint = chrono::system_clock::now();

        float fps = 1.0 / renderDuration.count();
        if (isFirstFrame == true)
        {
            isFirstFrame = false;
            continue;
        }
        if (renderDuration.count() < (1.0f / 60.0f))
            this_thread::sleep_for(chrono::milliseconds((int)(((1.0f / 60.0f) - renderDuration.count()) * 1000)));
        string fps_s = "FPS : " + to_string(fps);
        cout << fps_s << endl;

    }
}

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

int main(void)
{
    Init();
    Update();
    Release();

    exit(EXIT_SUCCESS);
}