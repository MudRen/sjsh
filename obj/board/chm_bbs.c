//chm'���԰�
//made by kissess on Mar 13,2002

#include <ansi.h>
inherit BULLETIN_BOARD;

void create()
{
        set_name(HIM"���ɹ���̨"NOR, ({ "board" }) );
        set("location", "/u/chm/workroom");
        set("board_id", "chm_bbs");
        set("long",     "������ʦ���ɵĹ���̨��\n" );
        setup();
        set("capacity", 200);
        replace_program(BULLETIN_BOARD);
}
