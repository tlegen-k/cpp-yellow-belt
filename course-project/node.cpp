#include "node.h"
using namespace std;

bool EmptyNode::Evaluate(const Date& date, const string& event) {
    return true;
}

bool DateComparisonNode::Evaluate(const Date& date, const string& event) {
    switch (cmp_) {
        case Comparison::Less : {
            return date < date_;
        }
        case Comparison::LessOrEqual : {
            return date <= date_;
        }
        case Comparison::Greater : {
            return date > date_;
        }
        case Comparison::GreaterOrEqual : {
            return date >= date_;
        }
        case Comparison::Equal : {
            return date == date_;
        }
        case Comparison::NotEqual : {
            return date != date_;
        }
        default :  {
            throw invalid_argument("Unknown comparison : (");
        }
    }
}

bool EventComparisonNode::Evaluate(const Date& date, const string& event) {
    switch (cmp_) {
        case Comparison::Less : {
            return event < event_;
        }
        case Comparison::LessOrEqual : {
            return event <= event_;
        }
        case Comparison::Greater : {
            return event > event_;
        }
        case Comparison::GreaterOrEqual : {
            return event >= event_;
        }
        case Comparison::Equal : {
            return event == event_;
        }
        case Comparison::NotEqual : {
            return event != event_;
        }
        default :  {
            throw invalid_argument("Unknown comparison : (");
        }
    }
}
bool LogicalOperationNode::Evaluate(const Date& date, const string& event) {
    switch(op_)
    {
    case LogicalOperation::Or: {
        return left_->Evaluate(date, event) || right_->Evaluate(date, event);
    }
    case LogicalOperation::And: {
        return left_->Evaluate(date, event) && right_->Evaluate(date, event);
    }
    default: {
        throw invalid_argument("Unknown operation:(");
    }
    }
}

