//lands'���԰� 
//made by lands

#include <ansi.h> 
inherit BULLETIN_BOARD; 

void create() 
{
        set_name(HIM"����ʯ"NOR, ({ "board" }) ); 
        set("location", "/u/lands/workroom"); 
        set("board_id", "kissess_b"); 
        set("long",     "�������µĹ���̨��\n" ); 
        setup(); 
        set("capacity", 200); 
        replace_program(BULLETIN_BOARD); 
}
