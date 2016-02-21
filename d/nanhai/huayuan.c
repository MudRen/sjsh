// 神话世界·西游记·版本（世纪）
/* <SecCrypt CPL V3R05> */
 
 
//huayuan.c
#include <ansi.h>
inherit ROOM;
void create ()
{
   set ("short", "后花园");
   set ("long", @LONG

这里是水母娘娘的后花园，四季如春，百花盛开，还有水母娘娘精心栽植
的灵芝(lingzhi)，这种仙草妙用无穷，据说乃是当年大圣国师王菩萨从寿
星处所得，后来传授给水母娘娘，水母娘娘精心培养，终于有了很大收成。
东面是水母娘娘的闺房。
LONG);
  set("outdoors", 1);
   set("item_desc", (["lingzhi" : "一株淡紫色的灵芝，吃了可以培元养气。 \n", ]));

   set("exits", 
   ([ //sizeof() == 1
     "east" : __DIR__"guifang",
   ]));
   
   set("objects", 
   ([ //sizeof() == 1
    "/d/nanhai/npc/sun"  : 1,
    "/d/nanhai/obj/moli"  : 1,
   ]));
   set("no_lingzhi", 0);

   setup();
}

void init()
{
   add_action("do_dig", "dig");
   add_action("do_dig", "wa");
}

int do_dig(string arg)
{

   object ob, me;
   
   me=this_player();

   if( (!arg) || (arg != "ling zhi" && arg != "lingzhi" && arg !="灵芝") )
     return notify_fail("你要挖什么？\n");

        if (objectp(present("sun shenjiang", environment(me))))
        return notify_fail("孙神将大怒：娘娘的东西岂能随便乱动呢。\n");

   if( !(ob = me->query_temp("weapon")) || ( (string)ob->query("skill_type")!="axe" && (string)ob->query("skill_type")!="blade" && (string)ob->query("skill_type")!="sword"  && (string)ob->query("skill_type")!="halberd" &&
     (string)ob->query("skill_type")!="halberd") ) 

     return notify_fail("得找个好工具吧。\n");

   if (query("no_lingzhi"))
     return notify_fail("还是给娘娘留个种吧，不然下次挖什么呢？\n");


   ob=new("/d/nanhai/obj/lingzhi");
           ob->move(me);
   message_vision("$N挖出一颗"+MAG"灵芝草"NOR+"，小心翼翼地藏到了怀里。\n", me);
   set("no_lingzhi", 1);
   call_out("regenerate", 3000);
   return 1;
}

int regenerate()
{
   set("no_lingzhi", 0);
   return 1;
}

