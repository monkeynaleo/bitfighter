//-----------------------------------------------------------------------------------
//
// bitFighter - A multiplayer vector graphics space game
// Based on Zap demo released for Torque Network Library by GarageGames.com
//
// Derivative work copyright (C) 2008 Chris Eykamp
// Original work copyright (C) 2004 GarageGames.com, Inc.
// Other code copyright as noted
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful (and fun!),
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//------------------------------------------------------------------------------------

#ifndef _FLAGITEM_H_
#define _FLAGITEM_H_

#include "item.h"

namespace Zap
{

class FlagItem : public Item
{
   typedef Item Parent;
   Point initialPos;
public:
   FlagItem(Point pos = Point());
   void onAddedToGame(Game *theGame);
   void processArguments(S32 argc, const char **argv);
   void renderItem(Point pos);
   void sendHome();

   void onMountDestroyed();
   bool collide(GameObject *hitObject);
   bool isAtHome();
   Timer mTimer;

   U32 packUpdate(GhostConnection *connection, U32 updateMask, BitStream *stream);
   void unpackUpdate(GhostConnection *connection, BitStream *stream);

   TNL_DECLARE_CLASS(FlagItem);
};

extern void renderFlag(Point pos, Color c);
extern void renderFlag(Point pos, Color c, F32 fraction);

};

#endif

