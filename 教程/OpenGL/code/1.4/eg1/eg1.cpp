#include"header/OpenGL.h"
using namespace std;

gl_t gl(0,800,600,"Learn OpenGL"); // 放在最前面
mesh_buf_t mb("res/eg1.ve","res/eg1.in",gle.draw_never_chg);
shader_t sd("res/eg1.vs","res/eg1.fs");
texture_t tx("res/box.jpg",0);

#include"header/sto.h" // 此文件中使用了 gl 对象，所以要写在它的定义之后 
void setup(){
	mb.bind();
	sd.use();
	tx.bind();
//	gl.line(); 
}
void show(){
	if(gl.kpr(GLFW_KEY_ESCAPE)) gl.close_win();
	gl.clr_rgb(0x000000); 
	gl.triangle(0,2);
}
int main(){ 
	setup();
	gl.main_loop(); 
	return 0;
}

