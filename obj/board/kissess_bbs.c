//kissess'���԰�
//made by kissess on Mar 12,2002

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIY"׷�繤��̨"NOR, ({ "board" }) );
        set("location", "/u/kissess/workroom");
        set("board_id", "kissess_bbs");
        set("long",     "������ʦ׷��Ĺ���̨��\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}

