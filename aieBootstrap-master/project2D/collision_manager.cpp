#include "collision_manager.h"
#include <cmath>

bool collision_manager::circle_vs_circle(
	const circle& a_circle_A,
	const circle& a_circle_B)
{
	glm::vec2 displacement = (a_circle_A.get_position() - a_circle_B.get_position());
	float sum_of_radii = a_circle_A.get_radius() + a_circle_B.get_radius();
	return (glm::length(displacement) < sum_of_radii);
}

//bool collision_manager::aabb_vs_aabb(
//	const aligned_bounding_box& a_aabb_A,
//	const aligned_bounding_box& a_aabb_B)
//{
//	return !(a_aabb_A.get_max().x < a_aabb_B.get_min().x ||
//			 a_aabb_A.get_min().x > a_aabb_B.get_max().x ||
//			 a_aabb_A.get_max().y < a_aabb_B.get_min().y ||
//			 a_aabb_A.get_min().y > a_aabb_B.get_max().y);
//}
//
//bool collision_manager::aabb_vs_circle(
//	const aligned_bounding_box& a_aabb,
//	const circle& a_circle)
//{
//	glm::vec2 clamped_centre = clamp(a_circle.get_position(), a_aabb.get_min(), a_aabb.get_max());
//	glm::vec2 displacement = clamped_centre - a_circle.get_position();
//	return (glm::length(displacement) < a_circle.get_radius());
//}

//bool collision_manager::circle_vs_line(
//	const circle& a_circle,
//	const line& a_line)
//{
//	float position_dot_normal = 
//		a_circle.get_position().dot(a_line.get_normal());
//	float distance = position_dot_normal -
//		(a_line.get_distance() + a_circle.get_radius());
//	return (distance < 0);
//}
//
//bool collision_manager::aabb_vs_line(
//	const aligned_bounding_box& a_aabb,
//	const line& a_line)
//{
	// #1 loop each corner and dot product the distance
	//		then the furthest negative distance is the corner of greatest overlap
	// float position_dot_normal =
	//	a_aabb.get_max().dot(a_line.get_normal());
	// float distance = position_dot_normal - a_line.get_distance();

//	glm::vec2 extents = 0.5f * a_aabb.get_extents();
//	glm::vec2 extents_neg_x = 0.5f * vector_2(-a_aabb.get_extents().x, a_aabb.get_extents().y);
//	
//	float dot_extents = extents.dot(a_line.get_normal());
//	float dot_extents_neg_x = extents_neg_x.dot(a_line.get_normal());
//
//	float radius = fmaxf(fabsf(dot_extents), fabsf(dot_extents_neg_x));
//
//	circle projection{ a_aabb.get_position() , radius };
//	return circle_vs_line(projection, a_line);
//}
//
//glm::vec2 collision_manager::clamp(
	//const glm::vec2& a_vector_2,
	//const glm::vec2& a_min,
	//const glm::vec2& a_max)
//{
	//return { fminf(fmaxf(a_vector_2.x, a_min.x), a_max.x),
			 //fminf(fmaxf(a_vector_2.y, a_min.y), a_max.y) };
//}