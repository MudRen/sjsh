inherit ROOM;
#include <ansi.h>
void create()
{
set("short", HIR"�������"NOR);
set("long", @LONG
  
�����ޱߵĴ���һ�ۿ�ȥ���ƺ��ޱ��޼ʣ���Զ��������ͷ��
ǰ��ı���������һ���ߴ�ľ���������ע�����㡣
  
LONG);
        set("exits", 
        ([ 
        "up" : "/d/liudao/one/jitan",
                        ]));
set("objects", ([ /* sizeof() == 1*/ 
__DIR__"npc/luohou" : 1,
]));
setup();
}
void init()
{   
          add_action("block_cmd","",1);         
}
int block_cmd()
{
string verb = query_verb();
if (verb=="score") return 1; 
return 0;
}
