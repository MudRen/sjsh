// changan lingtai
// room1.c

inherit ROOM;

void create()
{
  set ("short", "ʥ��");
  set ("long", @LONG

��̨ʥ��֮ʥ��Ĵ�Ʈ���ŴӰ˸������������������̡���
ϸ�����ð˸��󶦣���Զ��֮����������˿˿���̣����д�
�㣬��������������Ʈ�ݣ��޲������Ŀ��������˸����л���
�Ű����Ĺ⣬ʹ���������κλ��Ҳ��ҹͨ����
LONG);
set("exits", ([ /* sizeof() == 4 */
"northwest": __DIR__"room4",
"north": __DIR__"shijie5",
"northeast": __DIR__"room5",
"west": __DIR__"room3",
"east": __DIR__"room2",
"south": __DIR__"guangchang",
]));
set("objects", ([
               "/d/lingtai/obj/danlu": 1,
               ]));
        set("no_clean_up", 0);
        set("outdoors", 1);
        setup();
}
void init()
{
        object who=this_player();
        if( (string)who->query("family/family_name")=="����ɽ���Ƕ�" ) {
        call_out("heal_up", 9, who);
        }
	remove_call_out("sounding");
	call_out("sounding", random(10), this_object());
}
int sounding(object where)
{
    string *msgs=({
    "�˸�����ͬʱƮ��һ�����̡�\n",
    "�˸����е����ͬʱ���˼�����\n",
    "��������Ϻ��ڴ����������\n",
    "����Ĺ��̻���һ��������\n",
  });
  tell_room (where,msgs[random(sizeof(msgs))]);
}

int heal_up(object who)
{
        if( !who || environment(who) != this_object() ){
		 return 1;
	}
/*
	if( (int)who->query("max_sen")==(int)who->query("eff_sen")
	&& 	(int)who->query("max_kee")==(int)who->query("max_kee") ){
		return 1;
	}
	
*/
        who->set("eff_gin", (int)who->query("max_gin"));
        who->set("eff_kee", (int)who->query("max_kee"));
        who->set("eff_sen", (int)who->query("max_sen"));

        message_vision("��������Ʈ��$N��$N�������˼�������\n", who);
        write("������Լ��ľ�����Ѫһ���Ӷ��ָ��ˡ�\n");

	if( (int)who->query("food") < (int)who->max_food_capacity() )
		who->set("food", (int)who->max_food_capacity());
	if( (int)who->query("water")< (int)who->max_water_capacity())
		who->set("water", (int)who->max_water_capacity());


        return 1;
}
