//changan city

inherit ROOM;

void create ()
{
        set ("short", "��Ҫ�鼮ר��");
        set ("long", @LONG

���ǳ�����һ���¿�����꣬�ഫ���ڵ��ϰ��ǻʹ��еĸ��Ʒ
�ƾ��Կ��Ա�֤��ר����İ���Ҳʮ�ֿ��������α��ڿ��С�����
�ɸɾ�����ǽ�Ϲ����˱�����������ؿ��ŵ����ҡ�
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
                "west" : "/d/city/guozi",
        ]));

        set("objects", 
        ([ //sizeof() == 1
                "/u/wen/npc/xixi" : 1,
        ]));
          set("no_time",1);
  set("no_fight", 1);
  set("no_magic", 1);
        set("freeze",1);  


//        set("outdoors", "changan");
	set("no_clean_up", 0);
        setup();
	replace_program(ROOM);
}


