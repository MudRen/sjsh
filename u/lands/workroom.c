#include <ansi.h> 
inherit ROOM; 
void create() 
{
set ("short",HIW"����С��"NOR); 
set ("long",@LONG 

�����˰���... ...
�Ҷ�֫���ƴ���Լ�˵
�ڷֱ�����ǰ���ҿ����������۾���
������ģ��ڴ󺣵�����������...
��ج��ڵ�����˲�������,������û
һƬ�ڰ�

LONG 
HIW @LONG 
������Ұ......

LONG NOR); 
set("exits",([ 
"kz":"/d/city/kezhan", 
"wr":"/d/wiz/wizroom", 
])); 
        set("objects",  
        ([ 
//           __DIR__"npc/keai" : 1, 
        ])); 
set("outdoors", 1); 
        set("no_time",1); 
        set("no_upgrade_age",1); 
        replace_program(ROOM); 
set("no_clean_up", 1); 
set("valid_startroom", 1); 
set("if_bed",1); 
setup(); 
//call_other( "obj/board/lands_b","???"); 
}
