#pragma once

#include <godot_cpp/classes/resource.hpp>
#include <godot_cpp/classes/texture2d.hpp>
#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/sprite_frames.hpp>

namespace godot {

class BalloonData : public Resource {
	GDCLASS(BalloonData, Resource)

private:
	Ref<Texture2D> sprite;
	Ref<SpriteFrames> spriteFrames;
	String anim_name = "";        

protected:
	static void _bind_methods();

public:
	void setSprite(const Ref<Texture2D> &p_sprite) { sprite = p_sprite; }
	Ref<Texture2D> getSprite() const { return sprite; }

	void setAnimName(const String &p_name) { anim_name = p_name; }
	String getAnimName() const { return anim_name; }

	void setSpriteFrames(Ref<SpriteFrames> frames);
	Ref<SpriteFrames> getSpriteFrames();
};

} // namespace godot
