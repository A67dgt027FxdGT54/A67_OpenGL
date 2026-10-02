#version 330 core
layout (location = 0) in vec3 v_pos;
uniform float xoffs; 
void main(){
    gl_Position=vec4(v_pos.x+xoffs,v_pos.y,v_pos.z,1.0);
}
