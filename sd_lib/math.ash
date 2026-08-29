float angle(vec2 v1,vec2 v2){
	return degrees(
		acos(
			clamp(
				dot(normalize(v1),normalize(v2)),
				-1.0, 
				1.0
			)
		)
	);
}
float angle(vec3 v1,vec3 v2){
	return degrees(
		acos(
			clamp(
				dot(normalize(v1),normalize(v2)),
				-1.0, 
				1.0
			)
		)
	);
}
float angle(vec4 v1,vec4 v2){
	return degrees(
		acos(
			clamp(
				dot(normalize(v1),normalize(v2)),
				-1.0, 
				1.0
			)
		)
	);
}
