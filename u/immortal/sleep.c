#include <ansi.h>
inherit ROOM;
void create()
{
set ("short",HIW "˯ ��" NOR);
set ("long",@LONG

           ��  ��  ��  ��         ��  ��  ��  ��

������ͥʼ������ů�ģ��񹬴��ɺ��������ھ�����������һ���������¹�
����Ե�����Ǽ�ͥ���������Ҹ���������ֵ������ǵ����񹬴���������š�
�����񹬴��װ�ޱȽϼ��ӣ������������ŵ�Ŭ���£�����øɸɾ���������
����������Ӵ���͸����ɴͶ�����񹬴��ĵ����ϣ�������¯�������̣���
�÷�����š�С���ӵĴ�����ɽ��ʯ�����񹬴�����������ʮ���꾫�ĵ�����
��������ͼ�����񹬴��ɺ�С�ɵ��İ��ᾧ�϶�������ʯ�ı�������׳�ɳ���
�����ͷ���������˷����Աߣ�Ϊ�˺��ӵİ�ȫ���񹬴��ɺ����ź����Լ���
Ԫ��û�������˫��ڷ��ں��ӷ��ŵ��������࣬��ħ��ֲ��ܽ��롣
�������񴲣��£ţģ��Ͱڷ��ڷ��С�
����������������Ҹ��ļң����ɵ���Ľ���������Ҹ����
LONG);
set("item_desc",(["bed":"˯���õĴ���(gosleep,gobed,bed)�� \n", ]));
set("exits",([
"out" : __DIR__"parlour",
]));
set("outdoors", 0);
set("objects", ([
__DIR__"obj/bed": 1,
]) );
setup();
}
void init()
{
add_action("do_bed", "gosleep");
add_action("do_bed", "gobed" );
add_action("do_bed", "bed");
}
int do_bed()
{
object me;
me=this_player();
message_vision(HIY "$N�ƿ�ɴ�ʣ�׼���ϴ��ˡ�\n\n" NOR, me);
me->move("/u/immortal/bed");
message_vision(HIY "\nɳ������һ����$N���˽�����\n" NOR, me);
return 1;
}
