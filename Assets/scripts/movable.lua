speed         = 1.0
delta_speed   = {}
delta_speed.x = 0.0
delta_speed.y = 0.0
delta_speed.z = 0.0
entity        = world:getEntity(entity_id)
velocity      = entity:getVelocity()
position      = entity:getPosition()
input_state   = input_handler:getInputState()

if input_state:test(eIC_GoLeft) then
	delta_speed.x = delta_speed.x - speed
end
if input_state:test(eIC_GoRight) then
	delta_speed.x = delta_speed.x + speed
end
if input_state:test(eIC_GoDown) then
	delta_speed.z = delta_speed.y - speed
end
if input_state:test(eIC_GoUp) then
	delta_speed.z = delta_speed.y + speed
end


velocity.x = velocity.x + delta_speed.x * delta_time
velocity.y = velocity.y + delta_speed.y * delta_time