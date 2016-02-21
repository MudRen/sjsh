// Room: /u/cnd/workroom.c
inherit ROOM;
#include <ansi.h>
void create ()
{
        set ("short", HIY "神龙岛" NOR);
         set ("long", @LONG

四面环海,处处青竹,莺鸣燕啼不绝于耳,这里是偏安海外的一个孤岛,
岛上风景迷人,没有任何人为加工过的痕迹,岛中央有一个小湖,湖中
停歇着各种迁徙经此的飞禽,湖旁安放着一张竹塌,远处隐隐传来淡淡
的吟诵声"天为被,地为床,风为衣衫,草做红毡,运天地之灵气,修我骨
肉皮囊.....
LONG);

            set("exits", ([
                    "out" :  "/d/city/center",
		    "in"  :  "/d/wiz/wizroom",
            ]));   


       set("no_fight",1);
       set("no_sleep", 1);
       set("valid_startroom", 1);

	set("no_clean_up", 0);
       setup();
	replace_program(ROOM);
}

void init() {
  
  object me->move("/d/dntg/hgs/flowerfruit");
}

