#pragma once

namespace leo
{

enum Event
{
  NOTHING = 0,
  COMPONENT_CREATED = 1,
  COMPONENT_UPDATED = 1 << 1,
  COMPONENT_DELETED = 1 << 2,
  COMPONENT_ADDED = 1 << 3,
  COMPONENT_REMOVED = 1 << 4,
  BASE_CREATED = 1 << 5,
  BASE_UPDATED = 1 << 6,
  BASE_DELETED = 1 << 7,
  BASE_ADDED = 1 << 8,
  BASE_REMOVED = 1 << 9,
  CUBE_MAP_UPDATED = 1 << 10
};
}
