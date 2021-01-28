void reader(...)
{
	lock(barrier);
	unlock(barrier);
	lock(rc_mutex);
	rc++;
	if (rc == 1)
	{
		lock(db_mutex);
	}
	unlock(rc_mutex);
	// Reading data
	lock(rc_mutex);
	rc--;
	if (rc == 0)
	{
		unlock(db_mutex);
	}
	unlock(rc_mutex);
}

void writer(...)
{
	lock(barrier);
	lock(db_mutex);
	// write data
	unlock(db_mutex);
	unlick(barrier);
}