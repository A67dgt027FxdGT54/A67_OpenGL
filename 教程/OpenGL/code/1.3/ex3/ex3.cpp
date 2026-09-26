#include"header/OpenGL.h"
using namespace std;

gl_t gl(0,800,600,"Learn OpenGL"); // 放在最前面
mesh_buf_t mb("res/ex3.ve","res/ex3.in",gle.draw_never_chg);
shader_t sd("res/ex3.vs","res/ex3.fs");

#include"header/sto.h" // 此文件中使用了 gl 对象，所以要写在它的定义之后 
void setup(){
	mb.bind();
	sd.use();
}
void show(){
	if(gl.kpr(GLFW_KEY_ESCAPE)) gl.close_win();
	gl.clr_rgb(0x000000); 
	sd.setf("xoffs",0.5f);
	gl.triangle(0,1);
}
int main(){ 
	setup();
	gl.main_loop(); 
	return 0;
}

