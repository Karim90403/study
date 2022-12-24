Parent(const Parent& obj)
{
    vector<Base*> ::iterator it;
    for (it = obj.v.begin(); it != obj.v.end(); it++) {
        Base* new_obj = (*it)->copy();
        v.push_back(new_obj);
    }
}

Child(const Child& obj): Parent(obj)
{
    vector<Base*> ::iterator it;
    for (it = obj.v1->begin(); it != obj.v1->end(); it++) {
        Base* new_obj = (*it)->copy();
        v1->push_back(new_obj);
    }
}
