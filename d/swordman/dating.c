inherit ROOM;

void create()
{
  set ("short", "������");
  set ("long", @LONG

��������ȵ����Ĵ��������������������������еĳ���Ŭ������
ϰ�Ž�����һλ��ʮ�����ҵ���Ů���ڴ���ָ�������ǡ�
LONG);
        set("objects", ([
                __DIR__"npc/xun": 1, 
                __DIR__"npc/dizi": 2, 

                                                
]));
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"wuguan",
        "east" : __DIR__"liangongshi",
              "west":__DIR__"xiuxishi",
]));
  setup();
}

