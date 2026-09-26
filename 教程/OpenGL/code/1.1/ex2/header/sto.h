#ifndef __A67_OpenGL_SETTINGS_H
#define __A67_OpenGL_SETTINGS_H 1
#include<bits/stdc++.h>
#include<windows.h>
#include<time.h>
#include<conio.h>

//#include ""
//using std::cin;
//using std::cout;



// 改变窗口大小之后将自动调用此函数。 
void framebuffer_size_callback(GLFWwindow* _win, int _w, int _h){
	glViewport(0,0,_w,_h);
    gl.set_win(_w,_h);
}

// 鼠标移动后将自动调用此函数。 
void mouse_callback(GLFWwindow* window, double xpos, double ypos){
	;
}

// 鼠标滚轮滚动后将自动调用此函数。 
void scroll_callback(GLFWwindow* window, double xoffset, double yoffset){
	;
}


#endif // __A67_OpenGL_SETTINGS_H
