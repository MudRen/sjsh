// jjf_b.c

inherit BULLETIN_BOARD;

void create()
{
          set_name("���԰�", ({ "board" }) );
set ("location","/d/pansi/tao_in.c");
          set("board_id", "pansi_b");
set("long", "�������԰棬������������ؼ�����˿�������ǵ�mud���\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
