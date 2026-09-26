#version 330 core
layout (location = 0) in vec3 v_pos;
out vec4 f_col;
void main(){
    gl_Position=vec4(v_pos.x,v_pos.y,v_pos.z,1.0);
    f_col=vec4(0.0f,0.0f,1.0f,1.0f); // blue
}
