inherit F_FOOD;
inherit ITEM;

void create()
{
        set_name("�޺˰�����", ({ "grape" }) );
        set_weight(350);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", "һ����������ˮ�ֵ��Ϻ��޺˰����ѡ�\n");
                set("unit", "��");
                set("value", 50);
                set("food_remaining", 5);
                set("food_supply", 60);
                set("material", "food");
        }
        setup();
}
int finish_eat()
{
        set_name("����Ƥ", ({"grape skin"}));
        set("value",0);
        set("long", "�޺˰����ѳ�ʣ��Ƥ��\n");
        return 1;
