#include "balloonData.h"

using namespace godot;

void BalloonData::_bind_methods() {
	// Bind setters/getters
	ClassDB::bind_method(D_METHOD("setSprite", "sprite"), &BalloonData::setSprite);
	ClassDB::bind_method(D_METHOD("getSprite"), &BalloonData::getSprite);

	ClassDB::bind_method(D_METHOD("setAnimName", "animName"), &BalloonData::setAnimName);
	ClassDB::bind_method(D_METHOD("getAnimName"), &BalloonData::getAnimName);

	ClassDB::bind_method(D_METHOD("setSpriteFrames", "frames"), &BalloonData::setSpriteFrames);
	ClassDB::bind_method(D_METHOD("getSpriteFrames"), &BalloonData::getSpriteFrames);

	// Register properties for editor
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "sprite", PROPERTY_HINT_RESOURCE_TYPE, "Texture2D"),
			"setSprite", "getSprite");

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "frames", PROPERTY_HINT_RESOURCE_TYPE, "SpriteFrames"),
			"setSpriteFrames", "getSpriteFrames");

	ADD_PROPERTY(PropertyInfo(Variant::STRING, "anim_name"),
			"setAnimName", "getAnimName");
}

void godot::BalloonData::setSpriteFrames(Ref<SpriteFrames> frames) {
	spriteFrames = frames;
}

Ref<SpriteFrames> godot::BalloonData::getSpriteFrames() {
	return spriteFrames;
}
