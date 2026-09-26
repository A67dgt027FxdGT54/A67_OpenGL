#include"header/OpenGL.h"
using namespace std;

gl_t gl(0,800,600,"Learn OpenGL"); // 放在最前面
mesh_buf_t mb("res/eg1.ve","res/eg1.in",gle.draw_never_chg);
shader_t sd("res/eg1.vs","res/eg1.fs");
timer_t tim;

#include"header/sto.h" // 此文件中使用了 gl 对象，所以要写在它的定义之后 
void setup(){
	mb.bind();
	sd.use();
}
void show(){
	if(gl.kpr(GLFW_KEY_ESCAPE)) gl.close_win();
	tim.upd();
	gl.clr_rgb(0x000000); 
	float red=sin(tim.cur)/2.0f+0.5f;
	sd.set3f("ucol",red,0.0f,0.0f);
	gl.triangle(0,1);
}
int main(){ 
	setup();
	gl.main_loop(); 
	return 0;
}

