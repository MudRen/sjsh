// jjf_b.c

inherit BULLETIN_BOARD;

void create()
{
          set_name("留言版", ({ "board" }) );
set ("location","/d/pansi/tao_in.c");
          set("board_id", "pansi_b");
set("long", "这是留言版，上面密密麻麻地记着盘丝洞弟子们的mud生活。\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}
