//����

inherit ROOM;

void create ()
{
        set ("short", "�������ͼ����");
        set ("long", @LONG

��һ���žͿ������õ�Ϧ�ո���,���ﵽ����һƬ����
�����ǵ�������,ʱ����Щ���ŵ�,ʱ����Щ���ŵ�,��
��Щ���ǵ����߶���ͣ�ŵ�... ...ǽ�����ý��ֿ���
��һЩ������ֺ�ͼ��,�����������������͵��书,
�����Ƕ������������˶��ٿ��Ѳŵõ������������,
�����г�һ����Ҳ���������Ӱ��.  ... ...
LONG);

        //set("item_desc", ([" *** " : " *** ", ]));

        set("exits", 
        ([ //sizeof() == 4
          "west" : "/d/calvin/lanling/jie5",
          "east" : "/d/calvin/lanling/npcroom1",
        ]));

        set("objects", 
        ([ //sizeof() == 1
        ]));

        set("no_clean_up", 0);
        setup();
 call_other("/obj/board/lanling_b2","???");
        replace_program(ROOM);
}
