#include"header/OpenGL.h"
using namespace std;
gl_t gl(0,800,600,"Learn OpenGL");
#include"header/sto.h" // 此文件中使用了 gl 对象，所以要写在它的定义之后 
void show(){
	if(gl.kpr(GLFW_KEY_ESCAPE)) gl.close_win();
	gl.clr_rgb(0xffff00); 
}
int main(){ 
	gl.main_loop(); 
	return 0;
}

