//  SuperTux - Switch Trigger
//  Copyright (C) 2006 Christoph Sommer <christoph.sommer@2006.expires.deltadevelopment.de>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef HEADER_SUPERTUX_TRIGGER_SWITCH_HPP
#define HEADER_SUPERTUX_TRIGGER_SWITCH_HPP

#include <string>

#include "sprite/sprite.hpp"
#include "trigger/trigger_base.hpp"
#include "util/reader.hpp"
#include "video/drawing_context.hpp"

class Switch : public TriggerBase
{
public:
  Switch(const ReaderMapping& reader);
  virtual ~Switch();

  virtual void update(float elapsed_time);
  virtual void draw(DrawingContext& context);
  virtual void event(Player& player, EventType type);

private:
  enum SwitchState {
    OFF,
    TURN_ON,
    ON,
    TURN_OFF
  };

private:
  std::string sprite_name;
  SpritePtr sprite;
  std::string script;
  std::string off_script;
  SwitchState state;
  bool bistable;
};

#endif

/* EOF */
