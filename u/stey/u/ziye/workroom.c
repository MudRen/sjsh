#include <ansi.h>
inherit ROOM;
void create()
{
  set("short",HIR "��ҹ�Ĺ�����" NOR);
 set("long", @LONG
 ��������ҹ�Ĺ����ң��������̨���ԣ���û������ʲô�����ˣ�
ֻ��ǽ�ϴ��СС����������Ƭ������������һ��Ů���ӵģ�Ҳ���ǹ�
�˺ܾ��ˣ���������д˿������ˣ�����,ÿ����Ƭ���ܸɾ��ģ�����
��ҹ���������Ƭ��һ���ġ�
LONG); 
    set("no_time", 1);
    set("no_fight", 1);
    set("no_magic", 1);
    set("exits",([ 
       "shukai" : "/u/shukai/workroom.c",
       "kz" : "/d/city/kezhan.c",
       "repoo" : "/u/repoo/workroom.c",
       "wizroom" : "/d/wiz/wizroom.c",
       "33tian" : "/d/33tian/west1.c",
       "north" : "/u/ziye/jing.c",
       "fayu" : "/u/fayu/workroom.c", 
         "xuexu" : "u/xuexu/workroom" ,]));      set("objects",([
            "/u/ziye/npc/paopao":1]));
setup();
}

