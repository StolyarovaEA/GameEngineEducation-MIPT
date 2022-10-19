entity        = world:getEntity(entity_id)
velocity      = entity:getVelocity()
position      = entity:getPosition()
input_state   = input_handler:getInputState()
reload_timer  = entity:getReloadTimer()
ammo          = entity:getAmmo()


if input_state:test(eIC_Shoot) and  reload_timer  < 10. and ammo > 0 then
		bullet = world:getEntityByName("bullet")
		bullet:setVelocity(0.0, 0.0, 50)
		bullet:setPosition(position.x, position.y, position.z)
        bullet:setGravity(0.0, -9.81, 0.0)
		ammo = ammo - 1