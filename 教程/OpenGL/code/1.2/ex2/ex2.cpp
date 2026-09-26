#include"header/OpenGL.h"
using namespace std;

gl_t gl(0,800,600,"Learn OpenGL"); // 放在最前面
mesh_buf_t mb1("res/ex2.ve","res/ex2-1.in",gle.draw_never_chg),
		   mb2("res/ex2.ve","res/ex2-2.in",gle.draw_never_chg);
shader_t sd("res/ex2.vs","res/ex2.fs");

#include"header/sto.h" // 此文件中使用了 gl 对象，所以要写在它的定义之后 
void setup(){
	sd.use();
	gl.line(); 
}
void show(){
	if(gl.kpr(GLFW_KEY_ESCAPE)) gl.close_win();
	gl.clr_rgb(0x000000); 
	mb1.bind();
	gl.triangle(0,1);
	mb2.bind();
	gl.triangle(0,1);
}
int main(){ 
	setup();
	gl.main_loop(); 
	return 0;
}

