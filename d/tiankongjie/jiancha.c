// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */

inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "ͨ��");
  set ("long", @LONG

��������ս������ʦ������а���ܲ��档�Լ����ÿ��ǰɡ�
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "down" : "/d/changan/southseashore",
  "up" : __DIR__"bianjing",
]));
  set("objects", ([//sizeof() == 2
    __DIR__"npc/yiping" : 1,
__DIR__"npc/heimukai" : 1,
  ]));
  set("no_fight", 1);
  set("no_magic", 1);

  setup();
}
int block_cmd(string args)
{
string verb;
verb = query_verb();
    if (verb == "bian") return 1;
    if (verb == "xiudao") return 1;
    if (verb == "exert") return 1;
    if (verb == "cast") return 1; //by cjl
    if (verb == "fly") return 1; //by cjl
        return 0;
}

int valid_leave(object me, string dir)
{
    object guard, *inv, letter;
    int i;

    if(dir != "up")
        return ::valid_leave(me, dir);
    inv=all_inventory(me);
    i=sizeof(inv);
    me->delete_temp("condition/carrying_player");
    if(objectp(present("yiping", environment(me))))
   guard=present("yiping", environment(me));
    if(!guard) return ::valid_leave(me,dir);
    while (i--)
    {
        if (userp(inv[i]))
            me->add_temp("condition/carrying_player", 1);
        continue;
    }
    if(me->query_temp("condition/carrying_player"))
    {
        return notify_fail(CYN "����������ս磿�۲���ѽ��\n"NOR);
    }
    if (!(letter=present("shu xin", me)
       && letter->query("header")=="��ս���ˡ�") 
     && me->query("family/master_id")!="rigao yiping"
&& me->query("family/master_id")!="heimu kai"
&& me->query("family/master_id")!="li jia"
&& me->query("family/master_id")!="yintuo luo"
&& me->query("family/master_id")!="jixiang tian"
&& me->query("family/master_id")!="xie wu"
&& guard)
    {
        return notify_fail(CYN "�Ǻǣ����ڿɲ���Ӵ��������ս�Ŀɲ��ܽ�ȥӴ��\n"NOR);
    }

    //finally...
    return ::valid_leave(me, dir);
}

