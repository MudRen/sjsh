#include <ansi.h>
inherit ROOM;
void create()
{
   set("short",HIW "�۵�¥" NOR);
   set("long",@LONG
һ������ɫС�� ���滷ˮ ����һ����ˮ���ر߻���ӳˮ���죬����
��ϼ�������㣬�кɵ�㡣����Ƭ�غ컨�̲ݣ��ʵ��׷ɡ���ʱ���˱���
���з��ۣ�����������Ϸ�����������Ҳ��������������˸����飬�Ժ�
��һ�濪��һ���� ��ǰ����һ�������٣������һ������ɫ�����(bed)��
���������һ����ӣ����滹������֣������������Ʒ����塣���Ҹ�
��һ�ԡ�
LONG);
    set("exits",([
  "north" : "/u/shukai/workroom.c",
        ]));
      set("objects",([
               "/u/shukai/npc/ada" : 1,
               "/u/shukai/npc/baby" : 1,
                 ]));
  set("no_time",1);
        set("sleep_room",1);
        set("if_bed",1);
  set("alternative_die",1);
  set("valid_startroom", 1);
setup();
}
void init()
{
        add_action("do_dest", "cast");
        add_action("do_dest", "exert");
        add_action("do_back", "kissshukai");
        add_action("do_dest", "perform");
        add_action("do_dest", "bian");
        add_action("do_dest", "ji");
        add_action("do_dest", "throw");
        add_action("do_dest", "quit");
        add_action("do_dest", "home");
        add_action("do_dest", "punish");
        add_action("do_dest", "tojail");
        add_action("do_dest", "pop");
         add_action("do_dest", "nuke");
        add_action("do_dest", "shoot");
        add_action("do_dest", "go");
        add_action("do_dest", "goto");
        add_action("do_dest", "clone");
        add_action("do_dest", "fight");
        add_action("do_dest", "kill");
        add_action("do_dest", "dest");
        add_action("do_dest", "smash");

}

int do_back()
{

    this_player()->move("/d/city/kezhan");
    return 1;
}

int do_dest(string arg)
{
     return 1;
}
