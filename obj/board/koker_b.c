
inherit BULLETIN_BOARD;
#include <ansi.h>

void create()
{
            set_name("Ŷ��������԰�", ({ "board" }) );
          set("location", "/u/koker/workroom");
          set("board_id", "koker_b");
          set("long",     "������ʦŶ���Ϊ��λwiz���ҵ��������õİװ塣\n" );
	setup();
          set("capacity", 100);
	replace_program(BULLETIN_BOARD);
}
