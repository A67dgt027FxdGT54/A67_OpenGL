vec3 convolve(sampler2D atex, vec2 attex, float matrix[9], float offset){
	vec2 offs[9]=vec2[](
		vec2(-offset,-offset),
		vec2( 0.0   ,-offset),
		vec2( offset,-offset),
		vec2(-offset, 0.0   ),
		vec2( 0.0   , 0.0   ),
		vec2( offset, 0.0   ),
		vec2(-offset, offset),
		vec2( 0.0   , offset),
		vec2( offset, offset)
	);
	vec3 res=vec3(0.0);
	for(int i=0;i<9;i++){
		res += matrix[i] * vec3(texture(atex,attex+offs[i]));
	}
	return res;
}
