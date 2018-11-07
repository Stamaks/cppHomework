////////////////////////////////////////////////////////////////////////////////
// Module Name:  journal_net_activity.h/hpp
// Authors:      Leonid Dworzanski, Sergey Shershakov
// Version:      2.0.0
// Date:         28.10.2018
//
// This is a part of the course "Algorithms and Data Structures"
// provided by  the School of Software Engineering of the Faculty
// of Computer Science at the Higher School of Economics.
////////////////////////////////////////////////////////////////////////////////

// !!! DO NOT include journal_net_activity.h here, 'cause it leads to circular refs. !!!

#include <fstream>

//==============================================================================
// class JournalNetActivity
//==============================================================================

template <int numLevels>
void JournalNetActivity<numLevels>::parseLog(const std::string& fullpath)
{
    std::ifstream fin(fullpath);    // opens the file

    TimeStamp timestamp;            // dummy
    NetActivity netactivity;        // dummy

    while (fin)
    {
        fin >> timestamp;
        if (!fin)
            break;

        fin >> netactivity.user;
        if (!fin)
            break;

        fin >> netactivity.host;
        if (!fin)
            break;

        _journal.append(netactivity, timestamp);
    }
}

//------------------------------------------------------------------------------

template <int numLevels>
void JournalNetActivity<numLevels>::dumpJournal(std::ostream& out)
{
    typename NetActivityList::Node* prehead = _journal.getPreHead();
    typename NetActivityList::Node* run = prehead;

    // prehead is placed before the first and after the last element
    // So it serves two roles.
    while (run->m_next != prehead)
    {
        run = run->m_next;
        out << run->m_key;
        out << " ";
        out << run->m_value;
    }
}

//------------------------------------------------------------------------------

template <int numLevels>
void JournalNetActivity<numLevels>::outputSuspiciousActivities(
        const std::string& hostSuspicious, const TimeStamp & timeFrom,
        const TimeStamp & timeTo) const
{
    // TODO: Implement this method!
}

