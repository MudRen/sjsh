//cnd
inherit NPC;

void read_txt(object who,string num);

void create()
{
	set_name("����",({"feng po","feng shen","po"}));
	set("gender", "Ů��");
	set("age", 35);
	set("long", "    \n�칬�и�������������Ҫ�η�����ʱ��û����\n�İ����ǲ��еġ�\n");

	set("attitude", "heroism");
	set("class", "xian");

	set("combat_exp", 60000);
	set("daoxing", 100000);

	setup();

	carry_object("/obj/loginload/skirt.c")->wear();
	carry_object("/obj/loginload/shoes.c")->wear();
	add_money("silver", 10);

}


void init()
{
  	add_action("do_read", "read");
}


void do_read(string arg,string num)
{
	if (num == "age")
	{
	write("     �ԡԡԡԡԡԡԡԡԡԡԡ�������Ե����֪ͨ�ԡԡԡԡԡԡԡԡԡԡԡ�\n");
        write("     "+read_file("/topten/age.txt"));
        write("     �ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n");
	}
	if (num == "dx")
	{
		write("     �ԡԡԡԡԡԡԡԡԡԡԡ�������Ե����֪ͨ�ԡԡԡԡԡԡԡԡԡԡԡ�\n");
        	write("     "+read_file("/topten/age.txt"));
        	write("     �ԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡԡ�\n");
        }
        return ;

}
