// entrance.c

#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
  set ("short","礼品屋走道");
        set("long", @LONG


这里是长安城最有名的地方,不单单因为这里看到的风景好,只是因为这里
的所有客人都可以通过这里来获得天神赠送的特别礼物.
你可以通过(paizi)知道该去的地方.

LONG);

        set("item_desc", ([
                "paizi": @TEXT
这里是礼品屋过道，目前我们的路向有：

           down        二楼雅座
           east        晓婷礼品屋
           west        花哥礼品屋
           south       贝贝礼品屋
           north       神侯礼品屋
           northwest   依依礼品屋
           northeast   飞雨礼品屋
           southeast   风铃礼品屋
           southwest   男孩礼品屋

TEXT ]) );
        set("exits", ([
                "down" : "/d/wiz/entrance",
                     "east" : "/u/calvin/giftroom",
               "west" : "/u/koker/giftroom1",
//                "south" : "/u/stey/giftroom/",
               "north" : "/u/leoy/giftroom",
               "northeast" : "/u/vider/giftroom",
"northwest" : "/u/ivy/giftroom",
 //               "northeast" : "/u/flash/giftroom",
                  "southeast" : "/u/mudring/giftroom",
//                "southwest" : "/u/toyboy/giftroom/",
         ]) );
        set("no_time",1);
        set("no_fight", 1);
        set("no_magic", 1);

  set("objects", ([ /* sizeof() == 1 */
]));
        setup();
}
/*
int valid_leave(object me, string dir)
{
        
        if(me->query("id")=="clock") return ::valid_leave(me, dir);
        if(me->query("id")=="net") return ::valid_leave(me, dir);
        if(me->query("id")=="weiqi") return ::valid_leave(me, dir);

        if( dir=="north" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}

void init()
{
        add_action("do_accuse", "accuse");
}

int do_accuse(string arg)
{
        object ob;
        string s;

        if( ob = find_player(arg) ) {
                if( ob==this_player() )
                        return notify_fail("你要检举自己？\n");
                if( ob->is_ghost() )
                        return notify_fail( ob->name(1) +
"已经死了，放他一马吧。\n");
                if( wizardp(ob) )
                        return notify_fail("你不能检举巫师。\n");
                tell_object(ob, HIW + this_player()->name(1) +
"检举你是个机器人，请你接受一个小小的测验。\n" NOR);
                ROBOT_CHECK->test_me(ob);
                write("Ok. 已经将你检举的对象送去做测验。\n");

write("为了避免有人用机器人乱检举骚扰别人，请你也接受相同的测验。\n");
                ROBOT_CHECK->test_me(this_player());
                log_file("robot_accuse",
                        sprintf("%s accused %s on %s.\n",
this_player()->query("id"), ob->query("id"), ctime(time())));
                return 1;
        }
        return notify_fail("目前线上并没有这位玩家。\n");
}
*/
void init()
{
    add_action("do_exert", "exert");
}
int do_exert(string arg)
{
        object who = this_player();
       object me = this_object();
   message_vision("这里不可以施展内功！”\n",who);
       return 1;
}

