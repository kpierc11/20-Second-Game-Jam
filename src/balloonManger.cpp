#include "balloonManager.h"
#include <godot_cpp/classes/display_server.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/viewport.hpp>

using namespace godot;

void godot::BalloonManager::_bind_methods() {
	ClassDB::bind_method(D_METHOD("setBalloonAmount", "balloonAmount"), &BalloonManager::setBalloonAmount);
	ClassDB::bind_method(D_METHOD("getBalloonAmount"), &BalloonManager::getBalloonAmount);

	// Register property so it shows in the inspector & scripts
	ADD_PROPERTY(PropertyInfo(Variant::INT, "balloonAmount"), "setBalloonAmount", "getBalloonAmount");
}

godot::BalloonManager::BalloonManager() {
}

godot::BalloonManager::~BalloonManager() {
}

void godot::BalloonManager::_ready() {
	balloonAmount = 20;
	mRng.instantiate();
	mRng->randomize();

	Vector2 windowSize = DisplayServer::get_singleton()->window_get_size();
	Viewport *vp = get_viewport();
	Rect2 vpRect = vp->get_visible_rect();
	Vector2 vpSize = vpRect.size;

	Ref<Texture2D> tex = ResourceLoader::get_singleton()->load("res://assets/sprites/balloon-red-sprite-v-1.png");
	for (int i = 0; i < balloonAmount; i++) {
		//Vector2 scale = Vector2(100 / tex->get_size().x, 100 / tex->get_size().y);

		float ranBalloonPos = mRng->randf_range(vpRect.position.x, vpRect.position.x + vpSize.x);

		float ranBalloonFloatSpeed = mRng->randf_range(20.0f, 50.0f);
		float speed = ranBalloonFloatSpeed;

		Balloon *balloon = memnew(Balloon);
		balloon->set_position(Vector2(ranBalloonPos, vpRect.position.y + vpSize.y + 10.0f));
		balloon->set_texture(tex);
		balloon->setSpeed(ranBalloonFloatSpeed);

		add_child(balloon);
		mBalloons.push_back(balloon);
	}
}

int godot::BalloonManager::getBalloonAmount() {
	return balloonAmount;
}

void godot::BalloonManager::setBalloonAmount(int balloonCount) {
	balloonAmount = balloonCount;
}

void godot::BalloonManager::_process(double delta) {
	time_passed += delta;

	float amplitude = 50.0f;
	float frequency = .9f;

	for (int i = 0; i < mBalloons.size(); i++) {
		Balloon *balloon = Object::cast_to<Balloon>(mBalloons[i]);

		// Compute new position relative to start
		Vector2 newPosition;
		newPosition.x = balloon->get_position().x + cos(time_passed * frequency);

		newPosition.y = balloon->get_position().y + (balloon->getSpeed() * delta) * -1;

		// Apply new position to the sprite
		balloon->set_position(newPosition);
	}
}
