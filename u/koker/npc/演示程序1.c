//ʾ������
void die()
{
        object ob, me, corpse, obn;
        
        ob = this_object();
        me = query_temp("last_damage_from");
        
        message_vision(WHT"$N���һ��,��������!!���ض�����\n"NOR,ob,me);
        if( objectp(corpse = CHAR_D->make_corpse(this_object())) )
        corpse->move(environment(this_object()));
        message("vision", me->name() + "���������Ϸ����˴�����������\n", me);
        obn=new("/obj/money/gold");
        obn->set_amount(random(50));
        obn->move(me);
        destruct(ob);
        return;
}
